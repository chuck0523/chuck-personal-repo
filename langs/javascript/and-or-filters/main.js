const { promisify } = require('util')
const request = promisify(require('request'))
const { isUndefined } = require('lodash')

// Possible to be dynamic state by Redux or something
const state = {
  andOr: 'and',
  columns: [
    {
      name: 'id',
      andOr: 'and',
      filters: [
        { type: 'contains', text: '1' },
        { type: 'contains', text: '7' },
      ]
    },
    {
      name: 'name',
      andOr: 'or',
      filters: [
        { type: '', text: '' },
      ]
    },
    {
      name: 'email',
      andOr: 'or',
      filters: [
        { type: 'contains', text: 'org' },
        { type: 'contains', text: 'uk' },
      ]
    },
    {
      name: 'body',
      andOr: 'or',
      filters: [
        { type: 'contains', text: 'ullam' },
        { type: 'contains', text: 'voluptas' },
        { type: 'contains', text: 'quos' },
      ]
    }
  ]
}

// AND or OR functions
const AndOr = {
  'and': Array.prototype.every,
  'or': Array.prototype.some,
}
const matchers = {
  'any': () => true, // default
  'contains': (a, b) => a.includes(b),
  'equals': (a, b) => a === b,
}
const pickMatcher = (type = 'any') => {
  return matchers[type]
}

// State resolvers
// Array of andOr like ['and', 'or', 'or']
const andOrsState = state.columns.map(f => f.andOr)
// Array of filters
const filtersState = state.columns.map(c => c.filters)
// Array of types like [ ['contains', 'equals', 'contains'], [ ... ], ... ]
const typesState = filtersState.map(fs => fs.map(f => f.type))
// Array of texts like [ ['foo', 'bar', 'baz'], [ ... ], ... ]
const textsState = filtersState.map(fs => fs.map(f => f.text))

// Create functions
const andOrForColumn = AndOr[state.andOr]
const andOrsForCell = andOrsState.map(andOr => AndOr[andOr])
const matchersArray = typesState.map(types => types.map(pickMatcher))

// AND or OR search for data
const callFilters = (data) => {
  // Target: row
  return data.filter(row => {
    // Target: cell
    return andOrForColumn.call(matchersArray, (matchers, columnIndex) => {
      const cell = row[columnIndex]
      const andOrForCell = andOrsForCell[columnIndex]

      // apply multiple matchers for cell
      return andOrForCell.call(matchers, (matcher, matcherIdex) => {
        const text = textsState[columnIndex][matcherIdex]
        // skip when no filter
        if(text === '') {
          return true
        }
        return matcher(cell.toString(), text)
      })
    })
  })
}

// Data formatter
const toValues = (data) => {
  // from: { id: 1, name: 'foo' }, { id: 2, name: 'bar'}
  // to:   [ [ 1, 'foo' ], [ 2, 'bar' ] ]
  return data.map(({ id, name, email, body }) => [ id, name, email, body ])
}

request('https://jsonplaceholder.typicode.com/comments')
  .then(({ body }) => body)
  .then(JSON.parse)
  .then(toValues)
  .then(callFilters)
  .then(console.log)
  .catch(console.error)
