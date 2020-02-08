create table Employee(
	fname varchar(10) not null, mname varchar(10), lname varchar(10) not null,
	ssn number(5), bdate date, address varchar(50) not null,
	salary number(10,2) not null, sex char not null, Dno number(5),
	primary key(ssn), check(sex in ('M','F'))
);

create table Department5(
	deptno number(5), name varchar(10) unique, mssn number(5),
	primary key(deptno),
	foreign key(mssn) references Employee(ssn)
);

alter table Employee modify foreign key(Dno) references Department5(deptno) on delete cascade;

select * from user_cons_columns where table_name='DEPARTMENT5';
alter table Department5 drop constraint SYS_C0047509;
alter table Department5 modify foreign key(mssn) references Employee(ssn) on delete set null;

create table Location(
	address varchar(50), Dno number(5),
	primary key(address,Dno),
	foreign key(Dno) references Department5(deptno) 
);

create table Project(
	pno number(5), pname varchar(10), locn varchar(50), Dno number(5),
	primary key(pno,pname),
	foreign key(Dno) references Department5(deptno) on delete cascade
);

----------------------------------------------------------------------------------------------------------------------------

-- Q1
select Bdate, Address from EMPLOYEE where Fname='John' and Minit='B' and Lname='Smith';
select Fname,Minit,Lname,Address from EMPLOYEE,DEPARTMENT1 where EMPLOYEE.DNo = DEPARTMENT1.Dnumber and DEPARTMENT1.Dname='Research';

-- Q2
create view ProjDept as select * from PROJECT,DEPARTMENT1 where PROJECT.Dnum = DEPARTMENT1.Dnumber;
create view ProjDeptEmp as select * from ProjDept,EMPLOYEE where ProjDept.Mgr_ssn = EMPLOYEE.Ssn;
select Pnumber,Dnum,Lname,Address,Bdate from ProjDeptEmp where Plocation = 'Stafford';

-- Q3
select distinct Ssn, Fname, Salary from EMPLOYEE;

-- Q4
