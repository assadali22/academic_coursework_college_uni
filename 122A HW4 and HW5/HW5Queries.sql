# 1. List the account id, first and last name for all attendees who have 
# bought at least 2 tickets after the date 2022-09-24. (DONE)

SELECT A.account_id, A.first_name, A.last_name
FROM attendee A, ticket T, buys B
WHERE A.account_id = B.attendee_id AND B.item_id = T.item_id AND B.date_purchased > '2022-09-24'
GROUP BY A.account_id HAVING COUNT(*) >= 2;

# 2. List the item id, name, category, and price of the highest price 
# and lowest price item sold by the merchant with the website 
# ‘http://www.nguyen-murphy.com/category.htm’ (DONE)

WITH murphyTable AS (SELECT I.item_id, I.name, I.category, I.price
FROM item I, merchant M
WHERE I.merchant_id = M.account_id AND M.website = 'http://www.nguyen-murphy.com/category.htm')

SELECT M1.item_id, M1.name, M1.category, M1.price FROM murphyTable M1
WHERE M1.price IN (SELECT MAX(M2.price) AS maxPrice FROM murphyTable M2) OR M1.price IN (SELECT MIN(M3.price) AS minPrice FROM murphyTable M3);

# FROM item I, merchant M, buys B (no need to use buys table, focus on items OFFERED by merchant)
# WHERE I.item_id = B.item_id

# 3. List the merchant id, item id, item name, item price, item category, 
# ad id and ad level for all unpurchased services that had an ad placed by 
# its merchant. Limit your output to the top 3 results ordered from highest 
# to lowest by price. (DONE)

SELECT I.merchant_id, I.item_id, I.name, I.price, I.category, A.ad_id, A.level
FROM ad A, merchant M, item I
WHERE A.item_id = I.item_id AND M.account_id = I.merchant_id AND I.merchant_id = A.merchant_id AND I.item_id NOT IN 
  (SELECT B.item_id FROM buys B, service S WHERE S.item_id = B.item_id)
ORDER BY I.price DESC
LIMIT 3;

# (SELECT B.item_id FROM ad A2, buys B, service S WHERE S.item_id = B.item_id AND B.item_id = A2.item_id) # (original subquery I came up with, which failed)

# SELECT S.item_id FROM ad A2, service S WHERE S.item_id = A2.item_id
# SELECT B.item_id FROM buys B, service S WHERE S.item_id = B.item_id
# (these two statements, when put in subquery, gave me the same results
# as my original subquery. Using only buys and service in subquery makes more logical sense;
# find purchased services, then find item_ids not in that result while getting the ads)

# -------------------------------------
# 4. Views [20 pts] (done)
# A merchant receives a classification of “High” if that merchant’s
# average rating is at least 4.4 out of 5. If a merchant’s average 
# rating is at least 2.6 but under 4.4, that merchant will receive a 
# “Medium” classification. If a merchant’s average rating is under 2.6, 
# that merchant will receive a “Low” classification.

# a) create a view called MerchantClassification that lists merchant account 
# ids, number of reviews, average rating, and classification for each merchant.

CREATE VIEW MerchantClassification(aid, numReviews, averageRating, classification) AS
(SELECT M.account_id, COUNT(M.account_id) AS review_count, ROUND(AVG(R.review_rating), 2) AS avg_rating, 
CASE 
 WHEN AVG(R.review_rating) < 2.6 THEN 'Low' 
 WHEN AVG(R.review_rating) >= 2.6 AND AVG(R.review_rating) < 4.4 THEN 'Medium'
 WHEN AVG(R.review_rating) >= 4.4 THEN 'High' ELSE NULL
 END AS classification
FROM merchant M, reviews R
WHERE M.account_id = R.reviewee_id
GROUP BY M.account_id
);


# b) Write a single SQL statement to list the number of merchants with 
# High, Medium, and Low classifications (done)
SELECT mc.classification, COUNT(mc.classification) AS classificationCount
FROM MerchantClassification mc
WHERE mc.classification = 'Low'
UNION
SELECT mc.classification, COUNT(mc.classification) AS classificationCount
FROM MerchantClassification mc
WHERE mc.classification = 'Medium'
UNION
SELECT mc.classification, COUNT(mc.classification) AS classificationCount
FROM MerchantClassification mc
WHERE mc.classification = 'High'


# 5. Stored Procedure (done)
# a) Create and exercise a SQL stored procedure called 
# InsertServiceAndPlaceAd() that can be used to simultaneously
# add a new service and place an ad for it.

DELIMITER $
CREATE PROCEDURE InsertServiceAndPlaceAd(p_item_id TEXT, p_name TEXT, p_price NUMERIC, p_category TEXT, p_description TEXT, p_merchant_id TEXT, p_date_listed DATE, p_frequency TEXT, p_ad_id INT, p_level TEXT, p_content TEXT)
 BEGIN
 
 INSERT INTO item (item_id, merchant_id, name, price, description, category, item_url, date_listed)
 VALUES (p_item_id, p_merchant_id, p_name, p_price, p_description, p_category, NULL, p_date_listed);
 
 INSERT INTO service (item_id, frequency)
 VALUES (p_item_id, p_frequency);
 
 INSERT INTO ad (ad_id, item_id, merchant_id, level, content)
 VALUES (p_ad_id, p_item_id, p_merchant_id, p_level, p_content);
 
 END$

DELIMITER ;

CALL InsertServiceAndPlaceAd(
'YYYYY', # item_id
'ZZZZZ', # name
3547.43, # price
'Housing', # category
'ski in ski out housing', # description
'0X722', # merchant_id
CURDATE(), # date_listed
'weekly', # frequency
999, # ad_id
'Gold', # level
'premier location' # content
);


# b) Verify that your stored procedure works properly by calling it as 
# follows to insert a new service and associated ad. Write an SQL query
# to show the stored procedure’s after-effects.

SELECT S.frequency, A.ad_id, A.merchant_id, I.item_id, I.date_listed
FROM service S, ad A, item I
WHERE A.merchant_id = I.merchant_id AND A.item_id = I.item_id AND S.item_id = I.item_id
AND A.ad_id = 999;


# c) Upon calling InsertServiceAndPlaceAd with values defined above, 
# what will happen?

# 999, 'YYYYY', '0X722', 'Gold', and 'premier location' will be inserted 
# into the ads table, matching the corresponding schema 
# ad(ad_id, item_id, merchant_id, level, content). [ad_id = 999, item_id = ‘YYYYY’, merchant_id = '0X722', etc]

# 'YYYYY' (item_id) and 'weekly' (frequency) will be inserted into the 
# services table, matching the corresponding schema service(item_id, frequency)

# 'YYYYY', '0X722', 'ZZZZZ', 3547.43, 'ski in ski out housing', 
# 'Housing', NULL, and CURDATE() will be inserted into the item table, 
# matching the corresponding schema item(item_id, merchant_id, name, price, description, category, item_url, date_listed)


# 6. Triggers (DONE)
# a. Create a new table TARGETEDADS(account_id, ad_id, PRIMARY
# KEY(account_id, ad_id)) that stores ads targeted for attendees based 
# on their category of interests. Then write a CREATE TRIGGER statement 
# to define a trigger that, after a merchant places an ad for a specific
# item, inserts a row into the TARGETEDADS table for each attendee that has a recorded
# interest in items of that category. Use the CREATE TRIGGER statement as well as needed.
# Your trigger should ignore duplicate inserts to the new table.


CREATE TABLE targetedAds
(
	account_id VARCHAR(50),
    ad_id VARCHAR(50),
    PRIMARY KEY (account_id, ad_id)
);

# got the subquery to work, attendeeinterest is a fake table, empty data
DELIMITER &
CREATE TRIGGER targetedAdUpdate AFTER INSERT ON ad FOR EACH ROW
BEGIN
INSERT IGNORE INTO targetedAds(account_id, ad_id)
SELECT C.account_id, A.ad_id
FROM category C, ad A, item I
WHERE C.category = I.category AND A.item_id = I.item_id;
END &

DELIMITER ;

# b) Execute the following INSERT and SELECT statements to show the
# effect of your trigger and report the results

INSERT INTO AD (ad_id, level, content, item_id, merchant_id)
VALUES ('ADT32457', 'gold', '5 star location', 'EA352', '4Z5VC');

SELECT COUNT(*) AS count
FROM targetedAds
WHERE ad_id = 'ADT32457';

# count = 595