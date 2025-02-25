-- tourist_office.partners definition

-- Drop table

-- DROP TABLE tourist_office.partners;

CREATE TABLE tourist_office.partners (
	company_name varchar(80) NOT NULL,
	afm varchar(10) NOT NULL,
	loc varchar(80) NOT NULL,
	typeservice varchar(30) NOT NULL,
	phone varchar(11) NOT NULL,
	email varchar(100) NOT NULL,
	financial_agreement text NOT NULL,
	username varchar(100) NOT NULL,
	"password" varchar(100) NOT NULL,
	ispartner bool NOT NULL,
	CONSTRAINT partners_pkey PRIMARY KEY (afm),
	CONSTRAINT unique_username UNIQUE (username)
);