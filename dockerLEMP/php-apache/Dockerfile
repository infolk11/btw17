FROM php:apache
RUN apt-get update && apt-get install -y \
  libpq-dev && rm -rf /var/lib/apt/lists/*
RUN docker-php-ext-install mysqli pdo_mysql pdo_pgsql pgsql
