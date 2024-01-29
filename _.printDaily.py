#!/usr/bin/env python3

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

GR = '\033[92m'
YL = '\033[93m'
MG = '\033[95m'
CY = '\033[96m'
RE = '\033[0m'

def printDaily():
    payload = { 'query': query }
    resp = requests.post( endpoint, json=payload )
    if resp.status_code != 200:
        print('/err', resp.status_code)
        return
    D = json.loads(resp.text)['data']['activeDailyCodingChallengeQuestion']['question']
    qid = D['questionId']
    name, nameslug = D['title'], D['titleSlug']
    typ_, diff = D['categoryTitle'], D['difficulty']
    love, hate = D['likes'], D['dislikes']
    tops = ', '.join([_['name'] for _ in D['topicTags']])
    sqList = [ _ for _ in D['similarQuestionList']]

    Name = f'{qid} - {GR}{name}{RE}'
    Typ_ = f'Type: {typ_}'
    Diff = f'Rank: {diff}'
    Like = f'Love: {love}✓ {hate}✖'
    Tops = f'Tags: {tops}'
    Hints = '\n\n'.join([ f'{i}: {_}' for i,_ in enumerate( D['hints']) ])
    print(f'{YL}Daily question{RE}\n')
    print(Name)
    print(Diff)
    print(Tops)
    print(Typ_)
    print(Like,'\n')
    print(Hints) if Hints else print('no hints')
    print()

    if not sqList:
        print('no similar problems')
    else:
        for i, sq in enumerate(sqList):
            print(f'{YL}Similar question{RE} {i + 1}\n')
            print( f'{sq['questionId']} - {GR}{sq['title']}{RE}' )
            tops = ', '.join([_['name'] for _ in sq ['topicTags']])
            print( f'Tags: {tops}' )
            print( f'Rank: {sq['difficulty']}' )
            print()

printDaily()

