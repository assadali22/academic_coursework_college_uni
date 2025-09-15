# 1 - List the item ids of the top 5 most expensive items in the Transportation category.
# simply get item ids in item table where I.category = "Transportation"
# order by price in descending order to get price from most to least expensive
SELECT I.item_id
FROM item I
WHERE I.category = "Transportation"
ORDER BY I.price DESC
LIMIT 5; # show only 5 rows


# 2 - List the website of merchants with a last name of 'Cox'
# do a natural join on merchant and attendee using account_id
# and a boolean expression to check for last name equal to Cox.
SELECT M.website
FROM merchant M, attendee A 
WHERE M.account_id = A.account_id AND A.last_name = 'Cox';


# 3 - List the first and last names and item price for attendees who purchased items that cost more
# than $1500. Order the results by price in descending order and limit the results to 5 records.
SELECT A.first_name, A.last_name, I.price
FROM attendee A, item I, buys B
WHERE A.account_id = B.attendee_id AND B.item_id = I.item_id AND I.price > 1500
ORDER BY I.price DESC
LIMIT 5;
# (join on attendee, buys, and item)


# 4 - List the account id and rating of attendees who rated a merchant that sells an item with item id 'QZ6SL'. 
# Order the results in descending order of the rating
SELECT A.account_id, R.review_rating
FROM attendee A, reviews R, item I
WHERE R.reviewee_id = I.merchant_id AND R.reviewer_id = A.account_id AND I.item_id = 'QZ6SL'
ORDER BY R.review_rating DESC;
# reviewee is the merchant who got reviewed. The attendee is the reviewer


# 5 - List email, first and last name of attendees who bought tickets and 
# hold a passport from the UK. (so you have to use buys and tickets table,
# do appropriate joins on attendee and passport, tickets and buys, and join
# the buys and attendee where attendee_id = account_id
SELECT DISTINCT A.email, A.first_name, A.last_name
FROM attendee A, passport P, buys B, ticket T
WHERE A.account_id = P.account_id AND T.item_id = B.item_id AND B.attendee_id = A.account_id AND P.passport_country = 'UK';


# 6 - List the passport ids in ascending order for attendees who are
# both athletes and merchants and hold a passport from the UK. (complete)
SELECT P.passport_number
FROM passport P, athlete ATH, merchant M
WHERE ATH.account_id = M.account_id AND M.account_id = P.account_id AND P.passport_country = 'UK'
ORDER BY P.passport_number ASC;


# 7 - List the ad ids and item price of advertisements that are associated 
# with an item of the category Transportation with a price under $300. Order 
# the results by ad id in ascending order and limit the results to 5 records (complete)
SELECT ad.ad_id, I.price
FROM ad, item I
WHERE I.item_id = ad.item_id AND I.price < 300 AND I.category = 'Transportation'
ORDER BY ad.ad_id ASC
LIMIT 5;

 
# 8. List the websites and work phone numbers of all the Merchants who 
# listed items for sale on the date “9/19/2022”. Limit your output to 5 records
# (complete)
SELECT M.website, PH.phone_number
FROM merchant M, phone PH
WHERE M.account_id = PH.account_id AND PH.kind = 'work' AND NOT EXISTS
(SELECT I.merchant_id, I.date_listed FROM item I WHERE NOT EXISTS
(SELECT I2.date_listed FROM item I2 WHERE I2.date_listed = '2022-09-19'))
LIMIT 5;
 
# PUT THE DATE IN QUOTES
 
 
# 9. Find the top-rated athlete(s) for each sport, based on their average 
# review rating. Only consider athletes who have received at least 3 reviews. 
# If there is a tie for the highest average rating in a sport, return all 
# tied athletes. Show the sport, account ID, first and last name, and 
# average rating (rounded to 2 decimals). (DONE)

WITH athleteAvgRatings AS (SELECT ath.sport, A.account_id, A.first_name, A.last_name, ROUND(avg(R.review_rating), 2) AS avgRating
FROM athlete ath, attendee A, reviews R
WHERE ath.account_id = A.account_id AND R.reviewee_id = ath.account_id
GROUP BY ath.sport, A.account_id, A.first_name, A.last_name
HAVING COUNT(R.review_rating) >= 3
ORDER BY ath.sport, avgRating DESC)

SELECT aar.sport, aar.account_id, aar.first_name, aar.last_name, aar.avgRating
FROM athleteAvgRatings aar, (SELECT MAX(avgRating) AS avgRating, sport FROM athleteAvgRatings GROUP BY sport) AS max_avg_ratings
WHERE max_avg_ratings.avgRating = aar.avgRating AND aar.sport = max_avg_ratings.sport




# scratch (correct query using with to get average ratings for each athlete)
#WITH athleteAvgRatings AS (SELECT ath.sport, A.account_id, A.first_name, A.last_name, ROUND(avg(R.review_rating), 2) AS avgRating
#FROM athlete ath, attendee A, reviews R
#WHERE ath.account_id = A.account_id AND R.reviewee_id = ath.account_id
#GROUP BY ath.sport, A.account_id, A.first_name, A.last_name
#HAVING COUNT(R.review_rating) >= 3
#)

# 2nd half of scratch, failed code
#SELECT highestRating.sport, highestRating.account_id, highestRating.first_name, highestRating.last_name
#FROM (SELECT ath2.sport, avg(R2.review_rating) AS maxAvgRating
# FROM athlete ath2, reviews R2
# WHERE ath2.account_id = R2.reviewee_id
# GROUP BY ath2.sport
# HAVING COUNT(R2.review_rating) >= 3) AS highestRating
#WHERE athleteAverageRatings.avgRating = highestRating.maxAvgRating
#AND athleteAverageRatings.sport = highestRating.sport


# sub query to find athletes with reviews?
# SELECT Sport.sport, A.account_id, A.first_name, A.last_name, R.review_rating
# FROM athlete Sport, attendee A, reviews R
# WHERE Sport.account_id = A.account_id AND R.reviewee_id = Sport.account_id;

 
 
# 10. Find the top 3 merchants whose items have the highest total number of 
# purchases. For each of them, also report the number of ads placed for their items.
# (done)

WITH topMerchants AS (SELECT COUNT(I.item_id) as itemCount, M.account_id
FROM buys B, item I, merchant M
WHERE B.item_id = I.item_id AND I.merchant_id = M.account_id
GROUP BY M.account_id
ORDER BY itemCount DESC LIMIT 3)

SELECT topMerchants.account_id, COUNT(A.ad_id) as adCount, topMerchants.itemCount
FROM ad A, topMerchants, item i
WHERE topMerchants.account_id = i.merchant_id AND i.item_id = A.item_id
GROUP BY topMerchants.account_id # need to group by account ids so that ad count grouping can work
ORDER BY COUNT(A.ad_id)


#SELECT I.item_id, M.account_id
#FROM buys B, item I, merchant M
#WHERE B.item_id = I.item_id AND I.merchant_id = M.account_id
#ORDER BY M.account_id DESC;

# (all problems complete)
