-- tourist_office.payment definition

-- Drop table

-- DROP TABLE tourist_office.payment;

CREATE TABLE tourist_office.payment (
	cardnumber varchar(17) NOT NULL,
	ownername varchar(40) NOT NULL,
	cardcvc varchar(4) NOT NULL,
	amount numeric NOT NULL
);