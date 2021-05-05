const mongoose = require('mongoose')

mongoose.connect('mongodb://localhost/nodeblog_db', {
    useNewUrlParser: true,
    useUnifiedTopology: true
})

const PostSchema = new mongoose.Schema({
    title: {type: String, require: true},
    content: {type: String, require: true},
    date: {type: Date, default: Date.now}
})

let Post = mongoose.model('Post', PostSchema)

// CREATE

Post.create({
    title: "First Post Title",
    content: "First Post Content, Lorem Ipsum..."
}, (error, post) => {
    console.log(error, post)
})

Post.create({
    title: "Second Post Title",
    content: "Second Post Content, Lorem Ipsum..."
}, (error, post) => {
    console.log(error, post)
})

// READ

Post.findById('5d9df4e8919e0407803a8a3f', (error,post) => {
    console.log(error, post)
})

Post.find({
	title: "First Post Title"
},(error,post) => {
	console.log(error, post)
})

// UPDATE

Post.findByIdAndUpdate('5d9df4e8919e0407803a8a3f', {
    title: "New Post Title"
}, (error, post) => {
    console.log(error, post)
})

// DELETE

Post.findByIdAndDelete('5d9df4e8919e0407803a8a3f', (error, post) => {
    console.log(error, post)
})
  