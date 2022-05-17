-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Check the crime scene logs - shows time of 10:15 and says 3x transcripts mention bakery
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";

-- Check the transcript -
--check cars exiting 10 mins after (Ruth)
--check ATM on Leggett Street before crime (Eugene)
--cirminal made call before leaving <1m saying take earliest flight tomorrow
SELECT name, transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%';

-- Check licence plate numbers - eight exit in time
SELECT activity, hour, minute, license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute <= 25 and minute >= 15;

--set of calls made in relevant time frame - caller is criminal
SELECT caller, receiver, duration FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

--Look at flights on day after - earliest flight is flight id 36 going to destination 4 from airport 8
SELECT origin_airport_id, destination_airport_id, hour, minute, id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour, minute;

--Look at passengers on that flight
SELECT passport_number from passengers
    JOIN flights ON passengers.flight_id = flights.id
    WHERE flight_id = 36;

--Check accounts used at atm
SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street");

--Combine queries on people list to narrow down suspects - Bruce
SELECT name FROM people
    WHERE
        passport_number IN (SELECT passport_number from passengers
        JOIN flights ON passengers.flight_id = flights.id
        WHERE flight_id = 36)
    AND
        phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60)
    AND
        license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute <= 25 and minute >= 15)
    AND
        id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street"));

--Check destination - fiftyville airport to NYC
SELECT id, full_name, city FROM airports WHERE id IN (8, 36);

--Check accomplice - Robin
SELECT name FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60 AND caller IN (SELECT phone_number FROM people WHERE name = "Bruce"));









