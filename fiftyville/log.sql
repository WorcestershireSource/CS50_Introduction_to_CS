-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Check the crime scene logs - shows time of 10:15 and says 3x transcripts mention bakery
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";

SELECT activity FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10;