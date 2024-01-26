import requests
import json

endpoint = 'https://leetcode.com/graphql'

query = """query getDailyChallenge {
  activeDailyCodingChallengeQuestion {
    date
    link
    question {
      questionId
      title
      titleSlug
      difficulty
      categoryTitle
      likes
      dislikes
      topicTags {
        name
      }
      hints
      similarQuestionList {
        questionId
        title
        titleSlug
        difficulty
        categoryTitle
          topicTags{
            name
          }
      }
    }
  }
}"""

def printDaily():
    payload = { 'query': query }
    resp = requests.post( endpoint, json=payload )
    if resp.status_code != 200:
        print('/err', resp.status_code)
        return
    D = json.loads(resp.text)['data']['activeDailyCodingChallengeQuestion']['question']
    qid = D['questionId']
    name, nameslug = D['title'], D['titleSlug']
    cate, diff = D['categoryTitle'], D['difficulty']
    love, hate = D['likes'], D['dislikes']
    tops = ', '.join([_['name'] for _ in D['topicTags']])
    sqList = [ _ for _ in D['similarQuestionList']]

    Name = f'{qid} - {name}'
    Cate = f'type: {cate}'
    Diff = f'rank: {diff}'
    Like = f'love: {love}✓:{hate}✖'
    Tops = f'type: {tops}'
    Hints = '\n\n'.join([ f'{i}: {_}' for i,_ in enumerate( D['hints']) ])
    print(Name)
    print(Diff)
    print(Cate)
    print(Tops)
    print(Like,'\n')
    print(Hints)
    print()
    for i, sq in enumerate(sqList):
        print('similar question',i + 1)
        print( f'{sq['questionId']} - {sq['title']}' )
        tops = ', '.join([_['name'] for _ in sq ['topicTags']])
        print( f'type: {tops}' )
        print( f'rank: {sq['difficulty']}' )
        print()

printDaily()

