BEGIN TRANSACTION;

CREATE TEMPORARY TABLE ips_backup(
    ip_from INTEGER UNIQUE,
    ip_to INTEGER UNIQUE,
    country_name TEXT,
    region_name TEXT,
    city_name TEXT,
    latitude REAL,
    longitude REAL
);

INSERT INTO ips_backup
     SELECT ip_from, ip_to, country_name, region_name, city_name, latitude, longitude
       FROM ips;

DROP TABLE ips;

CREATE TABLE IF NOT EXISTS ips (
    ip_from INTEGER UNIQUE,
    ip_to INTEGER UNIQUE,
    country_name TEXT,
    region_name TEXT,
    city_name TEXT,
    latitude REAL,
    longitude REAL
);

INSERT INTO ips
     SELECT ip_from, ip_to, country_name, region_name, city_name, latitude, longitude
     FROM ips_backup;

DROP TABLE ips_backup;

COMMIT;

VACUUM;
