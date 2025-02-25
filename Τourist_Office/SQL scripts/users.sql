-- tourist_office.users definition

-- Drop table

-- DROP TABLE tourist_office.users;

CREATE TABLE tourist_office.users (
	username varchar(100) NOT NULL,
	"password" varchar(100) NOT NULL,
	isadmin bool NOT NULL,
	phone varchar(11) NOT NULL,
	email varchar(100) NOT NULL,
	"name" varchar(30) NOT NULL,
	surname varchar(50) NOT NULL,
	CONSTRAINT users_pkey PRIMARY KEY (username)
);