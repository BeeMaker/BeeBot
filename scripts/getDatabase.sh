#!/bin/bash

function stringToDatabase () {
  psql -U postgres -d beecoin -c "$1"
}


while :
do
  request="/usr/bin/curl -H \"Accept: application/json\" \"https://bittrex.com/api/v1.1/public/"

  getBTC_USDT="$request""getmarketsummary?market=usdt-btc\""

  jsonData=`eval $getBTC_USDT`

  marketName=`echo $jsonData | jq -r '.result[0] .MarketName'`
  timeStamp=`echo $jsonData | jq -r '.result[0] .TimeStamp'`
  currency=`echo $jsonData | jq -r '.result[0] .Last'`

  printf "ADD $marketName - $timeStamp - $currency\n"


  stringToDatabase "INSERT INTO coinmarket (\"idcoin\", \"datetime\", \"currency\")
  VALUES (1, '$timeStamp', $currency);"

  sleep 10m

done
