/** 问题描述：
Table: Person

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| PersonId    | int     |
| FirstName   | varchar |
| LastName    | varchar |
+-------------+---------+
主键是 PersonId
Table: Address

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| AddressId   | int     |
| PersonId    | int     |
| City        | varchar |
| State       | varchar |
+-------------+---------+
主键是 AddressId
 *  为上述报表编写一个 SQL 查询，该报表为每个人提供以下信息，不论这些人是否有地址。
 *  FirstName, LastName, City, State
 */

 SELECT FirstName, LastName, City, State 
 FROM Person left JOIN Address
 on Person.PersonId = Address.PersonId;