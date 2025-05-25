from requests import Response, Session

URL = "https://www.fijlkam.it/dove-siamo/societ%C3%A0.html?cerca-societa=Cerca&start={start}"
HEADERS = { "Connection": "keep-alive", "User-Agent": "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:133.0) Gecko/20100101 Firefox/133.0" }
START = 0

data = []

session = Session()

while True:
    print(f"Getting from index {START}")

    res: Response = session.get(URL.format(start = START), headers = HEADERS)

    if not res.ok:
        raise Exception(f"Response has status code {res.status_code} with start={START}")

    print(res.text)

    break
