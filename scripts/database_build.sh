#!/bin/bash

function stringToDatabase () {
	psql -U postgres -d database_name -c "$1"
}

stringToDatabase "DROP DATABASE IF EXISTS BeeCoin"
stringToDatabase "CREATE DATABASE BeeCoin"

stringToDatabase "CREATE TABLE CoinID (
					id bigint PRIMARY KEY,
					marketCurrency char[5],
					baseCurrency char[5],
					strategy.rsi.buy float8
					strategy.rsi.sell float8
					strategy.macd.isPositif bool
					strategy.macd.gap)"

stringToDatabase "CREATE TABLE CoinMarket (
					idCoin bigint,
					dateTime timestamp,
					currency float8)"

stringToDatabase "CREATE TABLE OrderBook (
					idCoin bigint,
					dateTime timestamp,
					currency float8,
					)"
