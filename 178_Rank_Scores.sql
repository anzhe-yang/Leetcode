/** 问题描述：
+----+-------+
| Id | Score |
+----+-------+
| 1  | 3.50  |
| 2  | 3.65  |
| 3  | 4.00  |
| 4  | 3.85  |
| 5  | 4.00  |
| 6  | 3.65  |
+----+-------+

+-------+------+
| Score | Rank |
+-------+------+
| 4.00  | 1    |
| 4.00  | 1    |
| 3.85  | 2    |
| 3.65  | 3    |
| 3.65  | 3    |
| 3.50  | 4    |
+-------+------+

 *  编写一个 SQL 语句去排序分数，如果两个分数一样，那么这两个分数应该有相同的排名。
 *  下一个排名索引应是下一个连续的整数。
 */

SELECT Score, (SELECT count(*) FROM (SELECT DISTINCT Score s From Scores) temp WHERE s>=Score) Rank
FROM Scores
ORDER BY Score DESC
