create table employee(empno number(5),empname varchar(20) not null,gender char not null,
salary number(10,2) not null,address varchar(100) not null,Dno number(3), primary key(empno), 
check(gender in ('M','F')));

create table department(deptno number(3), deptname varchar(30) unique, location varchar(50), 
primary key(deptno));

alter table employee modify foreign key(Dno) references department(deptno);

insert into department values(24,'HR','3rd floor');
insert into employee values(123,'Parthivi','F',75000,'Thane',17);

insert into employee values(789,'Karina','T',35000,'Delhi',24);
insert into employee values(123,'Rohan','M',65000,'Manipal',24);
insert into department values(24,'IT','1st floor');
insert into department values(17,'HR','3rd floor');

delete from department where deptname='HR';
delete from department where deptname='HR'
*
ERROR at line 1:
ORA-02292: integrity constraint (B2DBSL28.SYS_C0039398) violated - child record
found

select * from user_cons_columns where table_name='EMPLOYEE';
alter table employee drop constraint SYS_C0039398;
alter table employee modify foreign key(Dno) references department(deptno) on delete cascade;
delete from department where deptname='HR';
1 row deleted.

alter table employee modify salary default 10000;
insert into employee (empno,empname,gender,address,Dno) values(789,'Karina','F','Delhi',17);

alter table employee add(DOB date);
update employee set DOB='16-JULY-2000' where empname='Parthivi';

select empname, to_char(DOB,'DD-MON-YYYY') from employee;
select empname, to_char(DOB,'DD-MON-YY') from employee;
select empname, to_char(DOB,'DD-MM-YY') from employee;

select empname, to_char(DOB,'YEAR') from employee;
select empname, to_char(DOB,'Year') from employee;
select empname, to_char(DOB,'year') from employee;

select empname, to_char(DOB,'DAY') from employee;
select empname, to_char(DOB,'Day') from employee;

select empname, to_char(DOB,'MONTH') from employee;
select empname, to_char(DOB,'Month') from employee;

select empname, last_day(DOB), to_char(last_day(DOB),'DAY') from employee where empname=&x;

select round(months_between(sysdate,DOB)/12,0) from employee;

select next_day(add_months(DOB,60*12),'SATURDAY') from employee;

select empname from employee where (extract(year from DOB))=&x;

select empname from employee where (extract(year from DOB)) between &x and &y;

select empname from employee where &x-to_char(DOB,'YYYY')=60;

-----------------------------------------------------------------------------------------------------------------------

create table DepartmentU(dept_name varchar(10) primary key,building number(2),budget number(10,2));

create table Course(course_id number(5) primary key,title varchar(10),dept_name varchar(10),credits 
number(5), constraint coursedeptname_fk foreign key(dept_name) references DepartmentU(dept_name));

create table Student(s_id number(5) primary key,name varchar(10) not null,dept_name varchar(10),
tot_cred number(5),constraint studdeptname_fk foreign key(dept_name) references DepartmentU(dept_name));

create table Instructor(i_id number(5) primary key,name varchar(10) not null,dept_name varchar(10),
salary number(10,2),constraint insdeptname_fk foreign key(dept_name) references DepartmentU(dept_name));

create table Takes(s_id number(5),course_id number(5),sec_id number(3),sem number(1),year number(4),
grade char, primary key(s_id,course_id,sec_id,sem,year));

create table Teaches(i_id number(5),course_id number(5),sec_id number(3),sem number(1),year number(4),
primary key(i_id,course_id,sec_id,sem,year));

create table Section(course_id number(5),sec_id number(3),sem number(1),year number(4),building 
number(2),roomno number(3),time_slot_id number(5), primary key(course_id,sec_id,sem,year));

create table Classroom(building number(2),roomno number(3),capacity number(4), 
primary key(building,roomno));

create table Advisor(s_id number(5),i_id number(5), primary key(s_id,i_id));

create table Timeslot(time_slot_id number(5),day varchar(10),start_time timestamp,end_time timestamp,
primary key(time_slot_id,day,start_time));

create table Prereq(course_id number(5),prereq_id number(5), primary key(course_id,prereq_id));

---------------------------------------------------------------------------------------------------------------------------

select name,dept_name from student;

select * from instructor where dept_name='Comp. Sci.';

select title from course where dept_name='Comp. Sci.' and credits=3;

select takes.course_id, title from takes,course where takes.course_id = course.course_id and takes.id = '12345';

select * from instructor where salary between 40000 and 90000;

select id from instructor where id not in (select distinct id from teaches);

select student.name,course.title,year from (takes natural join section) join course using (course_id) join student using(id) where room_number = '3128';

select student.name, course_id, course.title as c_name from (student natural join takes) join course using(course_id) where year = 2010;

select distinct T.name, T.salary as inst_salary from instructor T, instructor S where T.salary > S.salary and S.dept_name='Comp. Sci.';

select name from instructor where dept_name like '%omp%';

select name,length(name) from student;

select dept_name, substr(dept_name,3,3) from department;

select upper(name) from instructor;

select coalesce(credits,0) from course;
select nvl(credits,0) from course;

select name, salary, round(salary/300.0)*100 from instructor;
select name, salary, round(salary/3, -2) from instructor;