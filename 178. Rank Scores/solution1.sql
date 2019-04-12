# Write your MySQL query statement below

SELECT Scores.Score, COUNT(Ranking.Score) AS RANK
FROM Scores,(
    SELECT DISTINCT Score
    From Scores
    ) Ranking
WHERE Scores.Score <= Ranking.Score
GROUP BY Scores.Id, Scores.Score
ORDER BY Scores.Score DESC;