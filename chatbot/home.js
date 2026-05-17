
function addMessage(message, sender)
{
    let chatBox = document.getElementById("chatBox");

    let msgDiv = document.createElement("div");
    msgDiv.classList.add("message");
    msgDiv.classList.add(sender);

    msgDiv.innerHTML = message;

    chatBox.appendChild(msgDiv);

    chatBox.scrollTop = chatBox.scrollHeight;
}

function chatbotReply(userText)
{
    userText = userText.toLowerCase();

    if(userText.includes("hello") || userText.includes("hi"))
    {
        return "Hello! How can I help you today?";
    }

    else if(userText.includes("product"))
    {
        return "We provide laptops, mobiles, headphones, and smart watches.";
    }

    else if(userText.includes("price"))
    {
        return "Our product prices start from ₹999.";
    }

    else if(userText.includes("delivery"))
    {
        return "Delivery usually takes 3-5 business days.";
    }

    else if(userText.includes("contact"))
    {
        return "You can contact us at support@example.com";
    }

    else if(userText.includes("bye"))
    {
        return "Thank you for visiting. Have a great day!";
    }

    else
    {
        return "Sorry, I did not understand your question.";
    }
}

function sendMessage()
{
    let input = document.getElementById("userInput");

    let text = input.value.trim();

    if(text === "")
        return;

    addMessage(text, "user");

    let botResponse = chatbotReply(text);

    setTimeout(() => {
        addMessage(botResponse, "bot");
    }, 500);

    input.value = "";
}

document.getElementById("userInput")
.addEventListener("keypress", function(event){

    if(event.key === "Enter")
    {
        sendMessage();
    }

});