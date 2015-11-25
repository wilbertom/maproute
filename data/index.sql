
CREATE UNIQUE INDEX IF NOT EXISTS ips_index ON ips (
    ip_from,
    ip_to
);
