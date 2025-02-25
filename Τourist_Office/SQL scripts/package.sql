-- tourist_office.package definition

-- Drop table

-- DROP TABLE tourist_office.package;

CREATE TABLE tourist_office.package (
	packageid varchar(210) NOT NULL,
	accomid varchar(100) NULL,
	shipid varchar(100) NULL,
	airplaneid varchar(100) NULL,
	"cost" numeric NOT NULL,
	fromadmin bool NOT NULL,
	CONSTRAINT package_check CHECK ((((shipid IS NOT NULL) AND (airplaneid IS NULL)) OR ((shipid IS NULL) AND (airplaneid IS NOT NULL)))),
	CONSTRAINT package_pkey PRIMARY KEY (packageid),
	CONSTRAINT package_accomid_fkey FOREIGN KEY (accomid) REFERENCES tourist_office.accomondation(hotel_id) ON DELETE CASCADE,
	CONSTRAINT package_airplaneid_fkey FOREIGN KEY (airplaneid) REFERENCES tourist_office.airplanes(airid) ON DELETE CASCADE,
	CONSTRAINT package_shipid_fkey FOREIGN KEY (shipid) REFERENCES tourist_office.ships(shipid) ON DELETE CASCADE
);