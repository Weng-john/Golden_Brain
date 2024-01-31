var formUrl=[
    "https://forms.gle/FhQb41Bn8yHHpyaW9",
    "https://forms.gle/3HTu36nTc7VcdAow7",
    "https://forms.gle/ttSnEUJGUhPnhEAR9",
    "https://forms.gle/3cNA9ydkbh6jaZ6Q7",
    "https://forms.gle/q7JRAFfcDzvm2p8f8",
    "https://forms.gle/eet3YEvXTtxBjDZP7",
    "https://forms.gle/bHfriWwBba7pctUn8",
    "https://forms.gle/PySHaiebGQfapx4i7",
    "https://forms.gle/9EtpJBcggX4a53q38",
    "https://forms.gle/MMW5KUjJy46WtUZe6",
    "https://forms.gle/YckbXWVUzyTyzZHj9"
];

document.querySelector(".confirm").addEventListener("click",()=>{
    let sel= document.getElementById("race").value;
    if(sel%1===0){
        document.getElementById("loadingArea").classList.add("loadingArea");
        window.location.href= formUrl[sel-1];
        setTimeout(()=>{
            document.getElementById("loadingArea").classList.remove("loadingArea");
        }, 5000); 
    }
});