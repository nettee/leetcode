# Write your MySQL query statement below
DELETE
FROM Person
WHERE Id NOT IN (
    SELECT t.id FROM (
        SELECT min(Id) AS id
        FROM Person
        GROUP BY Email
    ) t
);
