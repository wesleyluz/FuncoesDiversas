// https://api.whatsapp.com/send?phone=+{{ *YOURNUMBER* }}&text=%20{{ *YOUR MESSAGE* }}

var yourNumber = "{{ your number in string}}"
var yourMessage = "{{ your message in string }}"

// %20 mean space in link
// %0a mean breakline 
// If you already had an array then you just join them with '%20'
// easy right

function getLinkWhastapp(number, message) {
  number = yourNumber
  message = yourMessage.split(' ').join('%20')

  return console.log('https://api.whatsapp.com/send?phone=' + number + '&text=%20' + message)
}

getLinkWhastapp()


function getLinkWhastapp(number, message) {
    message = message.replace(/(\r\n|\n|\r)/gm,"%0A")
    message = message.split(' ').join('%20')
  
    return console.log('https://web.whatsapp.com/send?phone=' + number + '&text=%20' + message)
  }
  
