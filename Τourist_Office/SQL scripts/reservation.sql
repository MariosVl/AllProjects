-- tourist_office.reservation definition

-- Drop table

-- DROP TABLE tourist_office.reservation;

CREATE TABLE tourist_office.reservation (
	reservation_id varchar(326) NOT NULL,
	user_id varchar(100) NOT NULL,
	package_id varchar(210) NOT NULL,
	start_date date NOT NULL,
	end_date date NOT NULL,
	ispaid bool NOT NULL,
	CONSTRAINT reservation_pkey PRIMARY KEY (reservation_id),
	CONSTRAINT reservation_package_id_fkey FOREIGN KEY (package_id) REFERENCES tourist_office.package(packageid) ON DELETE CASCADE,
	CONSTRAINT reservation_user_id_fkey FOREIGN KEY (user_id) REFERENCES tourist_office.users(username) ON DELETE CASCADE
);