SELECT INGREDIENT_TYPE, SUM(TOTAL_ORDER) AS TOTAL_ORDER
FROM ICECREAM_INFO AS I
LEFT JOIN FIRST_HALF AS F
ON F.FLAVOR = I.FLAVOR
GROUP BY INGREDIENT_TYPE;