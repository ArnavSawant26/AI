function calculatePerformance() {

    let p1 = parseInt(document.getElementById("p1").value);
    let p2 = parseInt(document.getElementById("p2").value);
    let p3 = parseInt(document.getElementById("p3").value);

    let productivity = (p1 + p2 + p3) / 3;

    // Example values for remaining categories
    let quality = 4;
    let teamwork = 4;
    let attendance = 5;
    let initiative = 4;

    let percentage =
        productivity * 0.30 +
        quality * 0.25 +
        teamwork * 0.20 +
        attendance * 0.15 +
        initiative * 0.10;

    percentage *= 20;

    // Expert Rules
    if(attendance == 5)
        percentage += 3;

    if(teamwork <= 2)
        percentage -= 5;

    if(productivity >= 4 && quality >= 4)
        percentage += 5;

    if(initiative <= 2)
        percentage -= 3;

    if(percentage > 100)
        percentage = 100;

    let rating = "";

    if(percentage >= 90)
        rating = "Outstanding";
    else if(percentage >= 80)
        rating = "Excellent";
    else if(percentage >= 70)
        rating = "Very Good";
    else if(percentage >= 60)
        rating = "Good";
    else if(percentage >= 50)
        rating = "Average";
    else
        rating = "Needs Improvement";

    document.getElementById("result").innerHTML =
        "Score: " + percentage.toFixed(2) + "%<br>" +
        "Rating: " + rating;
}