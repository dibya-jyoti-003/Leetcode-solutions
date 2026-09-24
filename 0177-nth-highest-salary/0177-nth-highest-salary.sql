CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
    select salary from (
        select e.salary,
        dense_rank() over(order by salary desc) as rnk
        from Employee e 
    ) as ranked_salary
    where rnk = N limit 1
  );
END