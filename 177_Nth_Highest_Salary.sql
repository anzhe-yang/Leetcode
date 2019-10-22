/** 问题描述：
+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+

+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| 200                    |
+------------------------+

 *  编写一个 SQL 语句去查询 Employee 表中第 N 高的工资。
 *  如果没有，返回 null 。
 */

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N=N-1;
  RETURN (
    SELECT IFNULL (
        (SELECT DISTINCT Salary
        FROM Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET N),
    NULL)
  );
END
