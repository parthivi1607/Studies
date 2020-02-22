SQL> declare
  2  message varchar2(20):='Hello, World!';
  3  begin
  4  dbms_output.put_line(message);
  5  end;
  6  /

PL/SQL procedure successfully completed.

SQL> SET SERVEROUTPUT ON
SQL> ;
  1  declare
  2  message varchar2(20):='Hello, World!';
  3  begin
  4  dbms_output.put_line(message);
  5* end;
SQL> declare
  2  message varchar2(20):='Hello, World!';
  3  begin
  4  dbms_output.put_line(message);
  5  end;
  6  /
Hello, World!

PL/SQL procedure successfully completed.

-------------------------------------------------------------
SQL> show err
No errors.
------------------------------------------------------------

SQL> declare
  2  grade char(1);
  3  begin
  4  grade:='&g';
  5  if grade='A' then
  6  dbms_output.put_line('excellent');
  7  elsif grade='B' then
  8  dbms_output.put_line('good');
  9  else
 10  dbms_output.put_line('nope');
 11  end if;
 12  end;
 13  /
Enter value for g: B
old   4: grade:='&g';
new   4: grade:='B';
good

PL/SQL procedure successfully completed.

--------------------------------------------------------------

create table studenttable(rollno number(5), gpa number(2,1));
insert into studenttable values(1,5.8);
insert into studenttable values(2,6.5);
insert into studenttable values(3,3.4);
insert into studenttable values(4,7.8);
insert into studenttable values(5,9.5);

-- Q1
SQL> declare
  2  g studenttable.gpa%TYPE;
  3  begin
  4  select gpa into g from studenttable where rollno = &r;
  5  dbms_output.put_line(g);
  6  end;
  7  /
Enter value for r: 2
old   4: select gpa into g from studenttable where rollno = &r;
new   4: select gpa into g from studenttable where rollno = 2;
6.5

PL/SQL procedure successfully completed.

-- Q2
SQL> declare
  2  grade varchar(2);
  3  gp studenttable.gpa%TYPE;
  4  begin
  5  select gpa into gp from studenttable where rollno = &r;
  6  if (gp>=9 and gp<=10) then
  7  grade:='A+';
  8  elsif (gp>=8 and gp<9) then
  9  grade:='A';
 10  elsif (gp>=7 and gp<8) then
 11  grade:='B';
 12  elsif (gp>=6 and gp<7) then
 13  grade:='C';
 14  elsif (gp>=5 and gp<6) then
 15  grade:='D';
 16  elsif (gp>=4 and gp<5) then
 17  grade:='E';
 18  else
 19  grade:='F';
 20  end if;
 21  dbms_output.put_line(grade);
 22  end;
 23  /
Enter value for r: 5
old   5: select gpa into gp from studenttable where rollno = &r;
new   5: select gpa into gp from studenttable where rollno = 5;
A+

PL/SQL procedure successfully completed.

-- Q3
SQL> declare
  2  doi DATE;
  3  dor DATE;
  4  dib number(5);
  5  fine number(5):=0;
  6  begin
  7  doi := '&i';
  8  dor := '&f';
  9  dib := to_date(dor,'dd/mm/yyyy') - to_date(doi,'dd/mm/yyyy');
 10  if (dib between 0 and 7) then
 11  fine := 0;
 12  elsif (dib between 8 and 15) then
 13  fine := 1*(dib-7);
 14  elsif (dib between 16 and 30) then
 15  fine := 1*15+2*(dib-15);
 16  else
 17  fine := 1*15+2*15+5*(dib-30);
 18  end if;
 19  dbms_output.put_line(dib);
 20  end;
 21  /
Enter value for i: 03-FEB-20
old   7: doi := '&i';
new   7: doi := '03-FEB-20';
Enter value for f: 20-FEB-20
old   8: dor := '&f';
new   8: dor := '20-FEB-20';
17

PL/SQL procedure successfully completed.

-- Q4
SQL> declare
  2  gp studenttable.gpa%TYPE;
  3  grade varchar(2);
  4  begin
  5  for i in 1..5 loop
  6  select gpa into gp from studenttable where rollno = i;
  7  grade:='';
  8  if (gp>=9 and gp<=10) then
  9  grade:='A+';
 10  elsif (gp>=8 and gp<9) then
 11  grade:='A';
 12  elsif (gp>=7 and gp<8) then
 13  grade:='B';
 14  elsif (gp>=6 and gp<7) then
 15  grade:='C';
 16  elsif (gp>=5 and gp<6) then
 17  grade:='D';
 18  elsif (gp>=4 and gp<5) then
 19  grade:='E';
 20  else
 21  grade:='F';
 22  end if;
 23  dbms_output.put_line('Roll.no. ' || i || '     Grade ' || grade);
 24  end loop;
 25  end;
 26  /
Roll.no. 1     Grade D
Roll.no. 2     Grade C
Roll.no. 3     Grade F
Roll.no. 4     Grade B
Roll.no. 5     Grade A+

PL/SQL procedure successfully completed.

-- Q5
SQL> alter table studenttable add (lettergrade varchar(2));

Table altered.

SQL> declare
  2  gp studenttable.gpa%TYPE;
  3  grade studenttable.lettergrade%TYPE;
  4  begin
  5  for i in 1..5 loop
  6  select gpa into gp from studenttable where rollno = i;
  7  grade:='';
  8  if (gp>=9 and gp<=10) then
  9  grade:='A+';
 10  elsif (gp>=8 and gp<9) then
 11  grade:='A';
 12  elsif (gp>=7 and gp<8) then
 13  grade:='B';
 14  elsif (gp>=6 and gp<7) then
 15  grade:='C';
 16  elsif (gp>=5 and gp<6) then
 17  grade:='D';
 18  elsif (gp>=4 and gp<5) then
 19  grade:='E';
 20  else
 21  grade:='F';
 22  end if;
 23  update studenttable set lettergrade=grade where rollno=i;
 24  end loop;
 25  end;
 26  /

PL/SQL procedure successfully completed.

SQL> select * from studenttable;

    ROLLNO        GPA LE
---------- ---------- --
         1        5.8 D
         2        6.5 C
         3        3.4 F
         4        7.8 B
         5        9.5 A+

-- Q6
SQL> declare
  2  lead studenttable.rollno%type;
  3  maxno studenttable.gpa%type;
  4  var studenttable.gpa%type;
  5  begin
  6  lead := 1;
  7  select gpa into maxno from studenttable where rollno=1;
  8  for i in 2..5 loop
  9  select gpa into var from studenttable where rollno=i;
 10  if (var>maxno) then
 11  maxno := var;
 12  lead := i;
 13  end if;
 14  end loop;
 15  dbms_output.put_line('Roll.no. ' || lead || '     GPA ' || maxno);
 16  end;
 17  /
Roll.no. 5     GPA 9.5

PL/SQL procedure successfully completed.

-- Q7
SQL> declare
  2  gp studenttable.gpa%TYPE;
  3  grade varchar(2);
  4  begin
  5  for i in 1..5 loop
  6  select gpa into gp from studenttable where rollno = i;
  7  grade:='';
  8  if (gp>=9 and gp<=10) then
  9  goto ap;
 10  elsif (gp>=8 and gp<9) then
 11  goto aa;
 12  elsif (gp>=7 and gp<8) then
 13  goto bb;
 14  elsif (gp>=6 and gp<7) then
 15  goto cc;
 16  elsif (gp>=5 and gp<6) then
 17  goto dd;
 18  elsif (gp>=4 and gp<5) then
 19  goto ee;
 20  else
 21  goto ff;
 22  end if;
 23  <<ap>>
 24  grade:='A+';
 25  goto prnt;
 26  <<aa>>
 27  grade:='A';
 28  goto prnt;
 29  <<bb>>
 30  grade:='B';
 31  goto prnt;
 32  <<cc>>
 33  grade:='C';
 34  goto prnt;
 35  <<dd>>
 36  grade:='D';
 37  goto prnt;
 38  <<ee>>
 39  grade:='E';
 40  goto prnt;
 41  <<ff>>
 42  grade:='F';
 43  <<prnt>>
 44  dbms_output.put_line('Roll.no. ' || i || '     Grade ' || grade);
 45  end loop;
 46  end;
 47  /
Roll.no. 1     Grade D
Roll.no. 2     Grade C
Roll.no. 3     Grade F
Roll.no. 4     Grade B
Roll.no. 5     Grade A+

PL/SQL procedure successfully completed.

-- Q8
declare
nam instructor.name%TYPE;
val instructor%ROWTYPE;
begin
nam := '&n';
select * into val from instructor where name=nam;
dbms_output.put_line(val);
end;
/

-- Q9
declare
OutOfRangeExptn Exception;
gp studenttable.gpa%TYPE;
grade studenttable.lettergrade%TYPE;
begin
for i in 1..5 loop
select gpa into gp from studenttable where rollno = i;
grade:='';
if (gp>=9 and gp<=10) then
grade:='A+';
elsif (gp>=8 and gp<9) then
grade:='A';
elsif (gp>=7 and gp<8) then
grade:='B';
elsif (gp>=6 and gp<7) then
grade:='C';
elsif (gp>=5 and gp<6) then
grade:='D';
elsif (gp>=4 and gp<5) then
grade:='E';
elsif (gp>=0 and gp<4) then
grade:='F';
else
RAISE OutOfRangeExcptn;
end if;
update studenttable set lettergrade=grade where rollno=i;
end loop;
EXCEPTION
when OutOfRangeExcptn then
dbms_output.put_line('GPA out of range');
when others then
dbms_output.put_line('Error');
end;
/