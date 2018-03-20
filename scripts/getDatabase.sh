#!/bin/bash

while :
do
request="curl -H \"Accept: application/json\" \"https://bittrex.com/api/v1.1/public/"

getBTC_USDT="$request""getmarketsummary?market=usdt-btc\""

jsonData=`eval $getBTC_USDT`

marketName=`echo $jsonData | jq '.result[0] .MarketName'`
timeStamp=`echo $jsonData | jq '.result[0] .TimeStamp'`
currency=`echo $jsonData | jq '.result[0] .Last'`

sqlRequest="INSERT INTO CoinMarket (idCoin, dateTime, currency)
            VALUES(SELECT id FROM CoinID WHERE marketName=$marketName LIMIT 1,
            $timeStamp, $currency);"

idCoin=`psql -U postgres -d beecoin -c $sqlRequest`

sleep 10m

done
