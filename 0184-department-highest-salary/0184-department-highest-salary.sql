# Write your MySQL query statement below
select t.dept as Department ,t.emp as Employee, salary  
from (
    select d.name as dept,e.name as emp,e.salary as salary,
    rank() over(partition by e.departmentId order by e.salary desc) as rnk 
    from Employee e join Department d on e.departmentId = d.id
)as t
where t.rnk = 1;
