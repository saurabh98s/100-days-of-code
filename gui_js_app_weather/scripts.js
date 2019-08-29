window.addEventListener('load',()=>{
  let long;
  let lat;
  let temperatureDescription = document.querySelector('.temperature-description');
  let temperatureDegree = document.querySelector('.temperature-degree');
  let locationTimezone = document.querySelector('.location-timezone');

  if(navigator.geolocation){
    navigator.geolocation.getCurrentPosition(postion=>{
    long = postion.coords.longitude;
    lat = postion.coords.latitude;

    const proxy = "https://cors-anywhere.herokuapp.com/";
    const api = `${proxy}https://api.darksky.net/forecast/a3a6ea1f749ce80117a2caa3397257db/${lat},${long}`;

    fetch(api)
      .then(response=>{
        return response.json();
      })
      .then(data=> {
        console.log(data);
        const { temperature,summary,icon } = data.currently;
        // set DOM ELEMENTS from the API
        temperatureDegree.textContent = temperature;
        temperatureDescription.textContent = summary;
        locationTimezone.textContent = data.timezone;
        // Set Icon
        setIcons(icon,document.querySelector(".icon"));
      });
  });
  }

  function setIcons(icon,iconID){
    const skycons = new Skycons({ color: "white"});
    const currentIcon = icon.replace(/-/g,"_").toUpperCase();
    skycons.play();
    return skycons.set(iconID,Skycons[currentIcon]);
  }
});
