#!/bin/bash

function stringToDatabase () {
	psql -U postgres -d beecoin -c "$1"
}

stringToDatabase "DROP DATABASE IF EXISTS BeeCoin"
stringToDatabase "CREATE DATABASE BeeCoin"

stringToDatabase "CREATE TABLE CoinID (
					id SERIAL,
					marketName char[10],
					strategy_rsiBuy float8
					strategy_rsiSell float8
					strategy_macdIsPositif bool
					strategy_macdGap float8);"

stringToDatabase "CREATE TABLE CoinMarket (
					idCoin bigint,
					dateTime timestamp,
					currency float8);"

stringToDatabase "CREATE TABLE OrderBook (
					idCoin bigint,
					dateTime timestamp,
					currency float8
					);"


request="curl -H \"Accept: application/json\" \"https://bittrex.com/api/v1.1/public/"

getBTC_USDT="$request""getmarketsummary?market=usdt-btc\""

result=`eval $getBTC_USDT | jq -r '.result[0] .MarketName'`



stringToDatabase "INSERT INTO CoinID (marketName)
                  VALUES ($result)
                  "

