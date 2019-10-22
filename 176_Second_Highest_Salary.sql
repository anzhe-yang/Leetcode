/** 问题描述：
+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+

+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+

 *  编写一个 SQL 语句去查询 Employee 表中第二高的工资。
 *  如果没有，返回 null 。
 */

SELECT IFNULL (
    (SELECT DISTINCT Salary
    FROM Employee
    ORDER BY Salary DESC
    LIMIT 1 OFFSET 1),
    NULL
) AS SecondHighestSalary;

