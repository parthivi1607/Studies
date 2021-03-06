(select course_id from section where semester='Fall' and year=2009) union (select course_id from section where semester='Spring' and year=2010);

(select course_id from section where semester='Fall' and year=2009) intersect (select course_id from section where semester='Spring' and year=2010);

(select course_id from section where semester='Fall' and year=2009) minus (select course_id from section where semester='Spring' and year=2010);

select course_id from course where course_id not in (select distinct course_id from takes);

select distinct course_id from section where semester='Fall' and year=2009 and course_id in (select course_id from section where semester='Spring' and year=2010);

select count(distinct id) from takes where (course_id,sec_id,semester,year) in (select course_id,sec_id,semester,year from teaches where teaches.id=10101);

select distinct course_id from section where semester='Fall' and year=2009 and course_id not in (select course_id from section where semester='Spring' and year=2010);

select name from student where name in (select name from instructor);

select name from instructor where salary>some(select salary from instructor where dept_name='Biology');

select name from instructor where salary>all (select salary from instructor where dept_name='Biology');

select dept_name, avg(salary) from instructor group by dept_name having avg(salary)>=all (select avg(salary) as avg_sal from instructor group by dept_name);

select dept_name from department where budget<(select avg(salary) from instructor);

select course_id from section S where semester='Fall' and year=2009 and exists(select * from section T where semester='Spring' and year=2010 and S.course_id=T.course_id);

select distinct S.id, S.name from student S where not exists((select course_id from course where dept_name='Finance') minus (select T.course_id from takes T where S.id=T.id));

select course_id from course C where 1>=(select count(course_id) from section S where S.course_id=C.course_id and year=2009);

select id from student S where 1<(select count(T.course_id) from takes T, course C where T.course_id=C.course_id and C.dept_name='Comp.Sci.' and T.id=S.id);

select dept_name, avg_salary from (select dept_name,avg(salary) as avg_salary from instructor group by dept_name) where avg_salary>42000;

create view all_courses as (select C.course_id, building, room_number from course C, section S where C.course_id=S.course_id and year=2009 and semester='Fall' and dept_name='Physics');

select * from all_courses;

create view department_total_salary as (select dept_name, sum(salary) as total_salary from instructor group by dept_name);