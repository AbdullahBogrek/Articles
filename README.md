# JSON
- JSON "key ve value" çiftlerinden oluşan, verileri saklamak ve farklı platformlar arasında veri alışverişi yapmak için kullanılan ".json" uzantılı bir formattır.
  ```bash
  {"ad":"Abdullah", "soyad":"Bogrek"}
  ```
- Yapısı XML'e benzerdir. Fakat XML'e göre daha hızlı, daha az yer kaplar ve daha okunabilirdir. </br>
  XML                                          
  ```XML
  <employees>
    <employee>
      <name>Abdullah</name>
      <surname>Bogrek</surname>
      <age>21</age>
    </employee>
    <employee>
      <name>Omer</name>
      <surname>Faruk</surname>
      <age>20</age>
    </employee>
  </employees>
  ```
  JSON
  ```JSON
  {
    "employees" : [
    {
      "name" : "Abdullah",
      "surname" : "Bogrek",
      "age" : "21",
      "married" : "False" 
    },             
    {
      "name" : "Omer",
      "surname" : "Faruk",
      "age" : "20",
      "married" : "False" 
    }                   
                  ]
  }
  ```
- "Array, Object, Boolean, Number, String ve Null" veri tiplerini içerir. </br>
  Object
  ```JSON
  "employee" : {
    "ad" : "Abdullah"
  }
  ```
  Array
  ```JSON
  "employee":[      
  {"name" : "Abdullah", "surname" : "Bogrek", "age" : "21"},
  {"name" : "Omer", "surname" : "Faruk", "age" : "20"}
  ]
  ```
  Number ve Boolean
  ```JSON
  {"age" : "21", "married" : "false"}
  ```
  Null
  ```JSON
  {"id" : "null"}
  ```
- JSON verilerini diğer programlama dillerinde (C#, Python, C++, Java, vb.) kullanabilmek için komutlarla programlama diline ait veri yapısına dönüştürülmelidir.
  Python'da json ile işlemler yapabilmek için "json" kütüphanesini import etmeliyiz. JSON verilerini kullanmak için "load" fonksiyonunu, dict veri tipinde           yazılmış veriyi JSON formatına dönüştürmek için ise "dumps" fonksiyonu kullanılır.
  ```python
  import json

  employee = {
      "name" : 'Abdullah',
      "age" : 21,
      "education" : [
        {
            "BE": "NEU",
            "branch": "Computer Engineering",
            "not": 3.38
        }
      ]
  }
  kisi_json = json.dumps(kisi_dict)

  ```






  
