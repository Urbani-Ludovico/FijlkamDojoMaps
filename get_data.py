from bs4 import BeautifulSoup
from requests import Response, Session

URL = "https://www.fijlkam.it/dove-siamo/societ%C3%A0.html?cerca-societa=Cerca&start={start}"
HEADERS = { "Connection": "keep-alive", "User-Agent": "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:133.0) Gecko/20100101 Firefox/133.0" }
START = 0
LAST_PAGE = "0"

data = []

session = Session()

while True:
    print(f"Getting from index {START}")

    #
    # Get data
    #

    res: Response = session.get(URL.format(start = START), headers = HEADERS)

    if not res.ok:
        raise Exception(f"Response has status code {res.status_code} with start={START}")

    #
    # Parse HTML
    #

    html: BeautifulSoup = BeautifulSoup(res.text, "html.parser")
    body = html.body

    # Get page
    pagination = body.find("div", attrs = { "class": "pagination" })
    if pagination is None:
        raise ValueError("Pagination not found")
    current_page = pagination.find("span", attrs = { "class": "pagenav" })
    if current_page is None:
        raise ValueError("Current page not found")
    if current_page.text == LAST_PAGE:
        break
    LAST_PAGE = current_page.text

    break
