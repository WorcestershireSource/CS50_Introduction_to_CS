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

