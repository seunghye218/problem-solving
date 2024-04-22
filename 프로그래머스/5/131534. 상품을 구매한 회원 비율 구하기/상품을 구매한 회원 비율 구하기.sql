SELECT
    YEAR(SALES_DATE) AS YEAR, 
    MONTH(SALES_DATE) AS MONTH, 
    COUNT(DISTINCT USER_ID) AS PUCHASED_USERS, 
    ROUND(
        COUNT(DISTINCT USER_ID) /
        (SELECT COUNT (*) FROM USER_INFO WHERE YEAR(JOINED) = 2021)
    , 1) AS PUCHASED_RATIO
FROM USER_INFO AS I
JOIN ONLINE_SALE AS S
USING(USER_ID)
WHERE YEAR(JOINED) = 2021
GROUP BY YEAR, MONTH
ORDER BY YEAR, MONTH;

# 2021년에 가입한 전체 회원들 중 
# 상품을 구매한 회원수와 상품을 구매한 회원의 비율(=2021년에 가입한 회원 중 상품을 구매한 회원수 / 2021년에 가입한 전체 회원 수)
# 년, 월 별로 출력
# 상품을 구매한 회원의 비율은 소수점 두번째자리에서 반올림하고, 