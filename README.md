# SQL
A small version of what is called a relational database management system (DBMS), 
as well as a DSL (Domain Specific Language) with which a user can interact with your database.

- create table <TABLE_NAME> fields <FIELD_NAME> [, <FIELD_NAME> ...]
- make table <TABLE_NAME> fields <FIELD_NAME> [, <FIELD_NAME> ...]
- insert into <TABLE_NAME> values <VALUE> [, <VALUE> ...]
- select <\* | FIELD_NAME> [, <FIELD_NAME> ...] from <TABLE_NAME> where <FIELD_NAME> <RELATIONAL_OPERATOR> <VALUE> [<LOGICAL_OPERATOR> <FIELD_NAME><RELATIONAL_OPERATOR> <VALUE> ...]

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

## Design

change the repo name:
Can be found in https://github.com/hanbintan2003/SQL/design.txt

## Features

- it supports unlimitted amount of whitespaces between the input statement
- it supports complex boolean query statement for selection
- it supports prefix like selection using the keyword LIKE
- it supports permanent storage where the created tables will be stored inside the binary files
- it has a interactive mode where the user can type into command line and the input statement can be used to interact with the database
