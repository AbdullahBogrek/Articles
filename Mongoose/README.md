# Mongoose

Mongoose 'NodeJS' modülüdür. Geliştirilen uygulamaya göre model oluşturmamıza olanak sağlayan esnek ve şema tabanlı bir ORM yapısıdır. ORM'i [vikipedia](https://tr.wikipedia.org/wiki/Nesne-%C4%B0li%C5%9Fkisel_E%C5%9Fleme) "Nesne tabanlı programlama dilleri yapısına uygun olmayan katı veritabanı sorguları yerine veritabanı yapısının bir nesne gibi düşünülerek yazılım geliştirilmesine olanak sağlayan programlama teknolojisidir." diyerek açık bir şekilde açıklamıştır.

Mongoose "distributed" veritabanıdır. Bunun anlamı veritabanındaki veriler karmaşık bir şekilde saklanabilir. Ana bir bilgisayarda verilerin saklanmasına gerek yoktur. Ama bu verilerle yapılan işlemlerde zorluklar çıkarmaktadır. Bundan dolayı modelleme yapılmalıdır ve mongoose da bize bununla birlikte ORM'in sağladığı kolaylıkları MongoDB'de de kullanmamıza, JSON dosyaları ile CRUD işlemleri yapmamıza olanak sağlar.

Mongoose'u npm ile kolayca indirilir.
 ``` bash
 	npm install mongoose
 ```
 Kurulumdan sonra mongoDB ile işlemler yapabilmek için önce bağlantı oluşturulmalıdır.
 ``` javascript
	const mongoose = require('mongoose')

	mongoose.connect('mongodb://localhost/nodeblog_db', {
	    useNewUrlParser: true,
	    useUnifiedTopology: true
})
 ```
 Mongoose modülünü require fonksiyonu ile koda eklenir. Mongoose'un connect metotu ile adı "nodeblog_db" olan bir veritabanı oluşturulur. Connect metotu bu isimde bir veritabanı yoksa otomatik olarak kendisi oluşturacağından ayriyeten veritabanını oluşturmamıza gerek yoktur.
 
 Veriyi modellemek için ise "Schema" sınıfı kullanılır. Örnek olarak bir blog sitesinde post edileck blogların modelini ele alalım.
 ```javascript
    	const PostSchema = new mongoose.Schema({
 		title: {type: String, require: true},
		content: {type: String, require: true},
		date: {type: Date, default: Date.now}
    	})
 ```
 Örnekte de görüldüğü gibi 'title', 'content' gibi özellikler tiplerinin yanında çeşitli kısıtlamalar alabiliyor. Bu alanların doldurulmasını 'require' özelliği ile zorunlu yapıldı. Şema içinde metotlar da tanımlanabilir. Daha ayrıntılı bilgi için [mongoose dökümmanını](https://mongoosejs.com/docs/guide.html#methods) inceleyebilirsiniz.
 
 Bu modeli kullanabilmek için mongoose'un model metotu kullanılır. Kullanıma göre modeli export edebileceğiniz gibi modeli bir değişken ile birlikte de kullanılabilir.
 ```javascript
    	module.exports = mongoose.model('Post', PostSchema)
				or
    	let Post = mongoose.model('Post', PostSchema);
 ```
 Bu işlemden sonra modelin ismi ile 'CRUD' işlemleri yapılabilir. </br>
 Create (Veri Ekleme) : 'create' metotu ya da 'save' metotu kullanılarak yapılır.</br>
  ``` javascript
      	Post.create({
		title: "First Post Title",
		content: "First Post Content, Lorem Ipsum..."
     	}, (error, post) => {
		console.log(error, post)
     	})
  ```
  'Arrow Funciton' ile herhangi bir hata oluşursa bunu konsolda gösteriyoruz. Olmaz ise post konsolda gözükecektir. Herhangi bir hata yoksa çıktı olarak 'Null' değeri döndürecektir. </br>
  Read (Veri Sorgulama) : Veri sorgulama yapılırken MongoDB'nin içinde yer alan özelliklere göre sorgulama yapılabilir. Herhangi bir özelliğe göre sorgulama için 'find' metotu ya da 'id' değerine göre sorgulama için 'findById' metotu kullanılabilir. Daha farklı sorgulama metotları için [mongoDB'nin dökümanını](https://docs.mongodb.com/manual/reference/method/js-collection/) inceleyebilirsiniz. </br>
``` javascript
    	Post.find({
		title: "First Post Title"
    	},(error,post) => {
		console.log(error, post)
    	})
 ```
 - Id ile sorgulama, </br>
  
 ``` javascript
     	Post.findById('[id value]', (error,post) => {
		console.log(error, post)
     	})
 ```
  Farklı şekillerde yapılabilen sorgulama sonucunda bulunan verilerde güncellemeler yapılabilir.</br>
  Update (Veri Güncelle) : Veri sorgulama yapılırken MongoDB'nin içinde yer alan özelliklere göre sorgulama yapabiliyorduk. Bununla beraber sorgulama sonucu bulunan verilerde metotlar kullanarak manipülasyon yapılabilir. 'findOneAndUpdate', 'findByIdAndUpdate', 'updateMany' gibi metotlar ile sorgulama yapılır ve bulunan verilerd istenen güncellemeler yapılır. </br>
  ``` javascript
      	Post.findByIdAndUpdate('[id value]', {
		 title: "New Post Title"
      	}, (error, post) => {
		console.log(error, post)
	}
 ```
  Update işlemi gibi sorgulama yapılarak bulunan verileri silebiliriz.
  Delete (Veri Silme) : Sorgulama yapıp istenen veri ya da verileri bulup onları silebilir. Bunun için 'deleteOne', 'findByIdAndRemove', 'findOneAndRemove' gibi metotları kullanarak sorgulanan verileri silebiliriz. </br>
 ``` javascript
	Post.findByIdAndDelete('[id value]', (error, post) => {
		console.log(error, post)
	})
 ```
 Böylece nesne modelleme, CRUD işlemleri yaparak veriler üzerinde işlemler yapmayı gördük. Mongoose NodeJs ve MongoDB ile uygulama geliştirirken kullanılabilecek, verilerle yapılan işlemlerde kolaylık sağlayan bir modeldir.  </br>
 
  ## :books: Kaynaklar (References)
 - [Mongoose Documents](https://mongoosejs.com/docs/guide.html)
 - [MongoDB Documents](https://docs.mongodb.com/manual/crud/)
