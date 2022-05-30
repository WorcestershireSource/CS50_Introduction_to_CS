import os
import datetime

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    index_table = db.execute("SELECT * from current WHERE user_id = ?", session["user_id"])
    tmp = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
    balance = usd(tmp[0]["cash"])

    tmp2 = db.execute("SELECT stock, shares FROM current WHERE user_id = ?", session["user_id"])

    stock_totals = []
    for i in tmp2:
        stock = tmp2
        price = lookup(stock)
        value = tmp2[id]["shares"] * price["price"]
        tmp_dict = {"stock": tmp[id]["stock"], "value": value}
        stock_totals.append(tmp_dict)

    return render_template("index.html", index_table=index_table, balance=balance, stock_totals=stock_totals)



@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        #Check that a valid stock is provided
        symbol = request.form.get("symbol")
        stock = lookup(symbol)

        if not lookup(symbol):
            return apology("Not a recognised stock", 400)

        # Check a number of shares submitted
        if not request.form.get("shares") or not request.form.get("shares").isdigit():
            return apology("must provide number of shares", 400)

        #Calculate total cost and check there is sufficient balance
        total = float(stock["price"]) * float(request.form.get("shares"))

        balance = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

        new_balance = float(balance[0]["cash"]) - float(total)

        if new_balance < 0:
            return apology("Insufficient funds", 403)

        #If balance is sufficient then update the data base and return to default
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_balance, session["user_id"])
        db.execute("INSERT INTO transactions (user_id, stock, value, type, time, shares) VALUES (?, ?, ?, ?, ?, ?)", session["user_id"], symbol, total, "Buy", datetime.datetime.now(), request.form.get("shares"))

        current = db.execute("SELECT stock FROM current WHERE stock = ?", symbol)
        if len(current) != 1:
            db.execute("INSERT INTO current (user_id, stock, shares) VALUES (?, ?, ?)", session["user_id"], symbol, request.form.get("shares"))
        else:
            existing_shares = db.execute("SELECT shares FROM current WHERE user_id = ? AND stock = ?", session["user_id"], symbol)
            new_shares = int(existing_shares[0]["shares"]) + int(request.form.get("shares"))
            db.execute("UPDATE current SET shares = ? WHERE user_id = ? AND stock = ?", new_shares, session["user_id"], symbol)

        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    history = db.execute("SELECT * FROM transactions WHERE user_id = ?", session["user_id"])
    return render_template("history.html", history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("Must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("Must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("Invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":
        symbol = request.form.get("symbol")

        stock = lookup(symbol)

        if not lookup(symbol):
            return apology("Not a recognised stock", 400)

        price = usd(stock["price"])

        return render_template("quoted.html", symbol=symbol, price=price)

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("Must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password") or request.form.get("password") != request.form.get("confirmation"):
            return apology("Must provide password", 400)

        hash = generate_password_hash(request.form.get("password"))

        # Query database for username
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", request.form.get("username"), hash)

        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        stock = lookup(symbol)
        if not lookup(symbol):
            return apology("Not a recognised stock", 403)

        # Check a number of shares submitted
        if not request.form.get("shares"):
            return apology("Must provide number of shares", 403)

        #Calculate total cost and check there is sufficient balance
        total = float(stock["price"]) * float(request.form.get("shares"))

        balance = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

        new_balance = float(balance[0]["cash"]) + float(total)

        #Check there are shares to sell
        existing_shares = db.execute("SELECT shares FROM current WHERE user_id = ? AND stock = ?", session["user_id"], symbol)
        new_shares = int(existing_shares[0]["shares"]) - int(request.form.get("shares"))

        if existing_shares[0]["shares"] < request.form.get("shares"):
            return apology("Not enough shares to sell", 403)

        #Update the database and return to default
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_balance, session["user_id"])
        db.execute("INSERT INTO transactions (user_id, stock, value, type, time, shares) VALUES (?, ?, ?, ?, ?, ?)", session["user_id"], symbol, total, "Sell", datetime.datetime.now(), request.form.get("shares"))

        db.execute("UPDATE current SET shares = ? WHERE user_id = ? AND stock = ?", new_shares, session["user_id"], symbol)

        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        choices = db.execute("SELECT stock FROM current WHERE user_id = ?", session["user_id"])
        return render_template("sell.html", choices=choices)
