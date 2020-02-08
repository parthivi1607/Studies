-- Q1
create table employee(emp_no number(5),emp_name varchar(20),emp_address varchar(100));

-- Q2
insert into employee values(28,'Parthivi','Thane');

-- Q3
select emp_name from employee;

-- Q4
select emp_name from employee where emp_address='Manipal';

-- Q5
alter table employee add(salary number(10,2));

-- Q6
update employee set salary='75000' where emp_name='Parthivi';

-- Q7
desc employee;

-- Q8
delete from employee where emp_address='Mangalore';

-- Q9
rename employee to employee1;

-- Q10
drop table employee1;