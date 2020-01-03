# Write your MySQL query statement below
SELECT today.Id
FROM Weather yesterday INNER JOIN Weather today
    ON TO_DAYS(yesterday.RecordDate) + 1 = TO_DAYS(today.RecordDate)
WHERE today.Temperature > yesterday.Temperature
