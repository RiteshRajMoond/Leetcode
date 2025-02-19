# Write your MySQL query statement below

select eu.unique_id, e.name
from employees as e
left join employeeuni as eu
on eu.id = e.id;