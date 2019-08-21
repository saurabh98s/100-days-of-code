// request.setRequestHeader('Access-Control-Allow-Origin','*');
// request.setRequestHeader('Content-type','application/json');
// request.setRequestHeader('Access-Control-Allow-Methods','GET');
const app = document.getElementById('root')

const logo = document.createElement('img')
logo.src = 'logo.jpg'

const container = document.createElement('div')
container.setAttribute('class', 'container')

app.appendChild(logo)
app.appendChild(container)

var request = new XMLHttpRequest()
request.open('GET', 'http://localhost:8000/books', true)
request.setRequestHeader('Access-Control-Allow-Origin','*');
request.setRequestHeader('Content-type','application/json');
request.setRequestHeader('Access-Control-Allow-Methods','GET');
request.onload = function() {
  // Begin accessing JSON data here
  var data = JSON.parse(this.response)
  if (request.status >= 200 && request.status < 400) {
    data.forEach(Book => {
      const card = document.createElement('div')
      card.setAttribute('class', 'card')

      const h1 = document.createElement('h1')
      h1.textContent = Book.Title

      const p = document.createElement('p')
      Book.Author = Book.Author.substring(0, 300)
      p.textContent = `${Book.Author}...`

      container.appendChild(card)
      card.appendChild(h1)
      card.appendChild(p)
    })
  } else {
    const errorMessage = document.createElement('marquee')
    errorMessage.textContent = `Gah, it's not working!`
    app.appendChild(errorMessage)
  }
}

request.send()
