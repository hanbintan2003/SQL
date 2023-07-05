# SQL_InCPP
A small version of what is called a relational database management system (DBMS), 
as well as a DSL (Domain Specific Language) with which a user can interact with your database.


## Preview

  ![preview.png](./image/preview.png)
## Reserved keywords

- create
- table
- fields
- insert
- into
- values
- select
- from
- where
- \*
- and, or
- !=, = , <, >, >=, <=

- create table <TABLE_NAME> fields <FIELD_NAME> [, <FIELD_NAME> ...]
- insert into <TABLE_NAME> values <VALUE> [, <VALUE> ...]
- select <\* | FIELD_NAME> [, <FIELD_NAME> ...] from <TABLE_NAME> where <FIELD_NAME> 
<RELATIONAL_OPERATOR> <VALUE> [<LOGICAL_OPERATOR> <FIELD_NAME><RELATIONAL_OPERATOR> <VALUE> ...]

## Design

It can be found in https://github.com/hanbintan2003/SQL/blob/main/design.txt

## Features

- it supports unlimited amount of whitespaces between the input statement
- it supports complex boolean query statements for selection
- it supports permanent storage where the created tables will be stored inside the binary files
- it has an interactive mode where the user can type into the command line and the input statement can be used to interact with the database
