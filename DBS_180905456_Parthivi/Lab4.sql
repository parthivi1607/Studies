select count(id),course_id from takes group by course_id;

select dept_name, count(id) from student group by dept_name having count(id)>10;

select dept_name,count(course_id) from course group by dept_name;

select dept_name,avg(salary) from instructor group by dept_name having avg(salary)>42000;

select sec_id,count(id) from takes where semester='Spring' and year=2009 group by sec_id;

select course_id from prereq order by course_id asc;

select * from instructor order by salary desc;

select max(tot_sal) from (select sum(salary) as tot_sal from instructor group by dept_name);
or
select max(sum(salary)) from instructor group by dept_name;

select dept_name, avg_salary from (select dept_name,avg(salary) as avg_salary from instructor group by dept_name) where avg_salary>42000;

with enrol(sec,num) as (select sec_id, count(distinct id) from takes where semester='Spring' and year=2010 group by sec_id) select sec,num from enrol where num in (select max(num) from enrol);

select distinct T2.id, I.name from takes T1 join teaches T2 using (course_id,sec_id,semester,year) join student S on (T1.id=S.id) join instructor I on (I.id=T2.id) where S.dept_name='Comp. Sci.';

select dept_name,csum,avg_sal from (select dept_name,count(*) as csum, avg(salary) as avg_sal from instructor group by dept_name) where csum>5 and avg_sal>50000;
or
select dept_name,count(*), avg(salary) from instructor group by dept_name having count(*)>5 and avg(salary)>50000;

with max_budget(value) as (select max(budget) from department) select budget,dept_name from department D, max_budget B where D.budget=B.value;

with dept_total(dept_name,value) as (select dept_name,sum(salary) from instructor group by dept_name), dept_total_avg(value) as (select avg(value) from dept_total) select dept_name from dept_total D1, dept_total_avg D2 where D1.value>D2.value;

with enrol(sec,num) as (select sec_id, count(distinct id) from takes where semester='Fall' and year=2009 group by sec_id) select sec,num from enrol where num in (select max(num) from enrol);

with tot_cred(dept_name,value) as (select dept_name,sum(tot_cred) from student group by dept_name), fin_dept as (select value from tot_cred where dept_name='Finance') select dept_name,T.value from tot_cred T, fin_dept F where T.value>F.value;

savepoint Q17;
delete from instructor where dept_name='Finance';
rollback to Q17;

savepoint Q18;
delete from course where dept_name='Comp. Sci.';
rollback to Q18;

savepoint Q19;
insert into department (dept_name) values ('IT');
update student set dept_name='IT' where dept_name='Comp. Sci.';
rollback to Q19;

savepoint Q20;
update instructor set salary=
case
when salary>100000 then salary*1.03
else salary*1.05
end;
rollback to Q20;

savepoint Q21;
insert into student select ID, name, dept_name,0 from instructor where ID<>76543;
rollback to Q21;

savepoint Q22;
delete from instructor where salary<(select avg(salary) from instructor);
rollback to Q22;