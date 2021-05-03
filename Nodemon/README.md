# Nodemon
Node.js tabanlı uygulamaların geliştirilmesinde kullanılan bir modüldür. Uygulamayı geliştirirken sunucunun sürekli olarak elle baştan başlatılmasının önüne geçerek dosyadaki herhangi bir değişiklik algılandığında otomatik olarak sunucuyu yeniden başlatarak kolaylık sağlayan yardımcı bir araçtır.
Nodemon modülünü indirirken global olarak ya da sadece development aşamasında kullanmak için indirilebilir.
- Nodemon paketini production kısmında değil de development kısmında kullanmak için;
``` 
	npm install nodemon --save-dev
```
- Global olarak kendi bilgisayarınıza indirmek için
``` 
	npm install -g nodemon
```
Proje dosyasında `npm init` ile oluşturulan `package.json` dosyasında indirilen modüllerin nasıl indirildiğini, versiyonlarını görebiliriz. 
``` 
	{
	  "name": "nodeblog",
	  "version": "1.0.0",
	  "description": "Node Blog Application",
	  "main": "index.js",
	  "scripts": {
	    "test": "echo \"Error: no test specified\" && exit 1"
	  },
	  "author": "Bogrek",
	  "license": "ISC",  
	  "dependencies": {
	    "express": "^4.17.1"
	  },
	  "devDependencies": {
	    "nodemon": "^2.0.7"
	  }
	}

```
Dosyada herhangi bir değişiklik yapıldığında sürekli olarak `node index.js` yazmak yerine nodemon modülü ile `nodemon index.js` yazarak sunucu herhangi bir değişlikte sunucu otomatik olarak baştan başlatılacak.


  ## :books: Kaynaklar (References)
 - [NPM - Nodemon](https://www.npmjs.com/package/nodemon)