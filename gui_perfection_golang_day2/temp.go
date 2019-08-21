package main

import (
	"bytes"
	"database/sql"
	"fmt"
	"net/http"

	"github.com/gin-gonic/gin"
	_ "github.com/go-sql-driver/mysql"
)

func main() {
	db, err := sql.Open("mysql", "root:czlq5hvu@tcp(127.0.0.1:3306)/books")
	if err != nil {
		fmt.Print(err.Error())
	}
	defer db.Close()
	// make sure connection is available
	err = db.Ping()
	if err != nil {
		fmt.Print(err.Error())
	}
	type Book struct {
		bookId int
		title  string
		author string
	}
	router := gin.Default()

	// GET a person detail
	router.GET("/book/:bookId", func(c *gin.Context) {
		var (
			book   Book
			result gin.H
		)
		id := c.Param("id")
		row := db.QueryRow("select bookID, title,authors from books where id = ?;", id)
		err = row.Scan(&book.bookId, &book.title, &book.author)
		if err != nil {
			// If no results send null
			result = gin.H{
				"result": nil,
				"count":  0,
			}
		} else {
			result = gin.H{
				"result": book,
				"count":  1,
			}
		}
		c.JSON(http.StatusOK, result)
	})

	// GET all persons
	router.GET("/books", func(c *gin.Context) {
		var (
			book  Book
			books []Book
		)
		rows, err := db.Query("select BookID, title, authors from books;")
		if err != nil {
			fmt.Print(err.Error())
		}
		for rows.Next() {
			err = rows.Scan(&book.bookId, &book.title, &book.author)
			books = append(books, book)
			if err != nil {
				fmt.Print(err.Error())
			}
		}
		defer rows.Close()
		c.JSON(http.StatusOK, gin.H{
			"result": books,
			"count":  len(books),
		})
	})

	// POST new person details
	router.POST("/person", func(c *gin.Context) {
		var buffer bytes.Buffer
		title := c.PostForm("title")
		authors := c.PostForm("authors")
		stmt, err := db.Prepare("insert into books (title, authors) values(?,?);")
		if err != nil {
			fmt.Print(err.Error())
		}
		_, err = stmt.Exec(title, authors)

		if err != nil {
			fmt.Print(err.Error())
		}

		// Fastest way to append strings
		buffer.WriteString(title)
		buffer.WriteString(" ")
		buffer.WriteString(authors)
		defer stmt.Close()
		name := buffer.String()
		c.JSON(http.StatusOK, gin.H{
			"message": fmt.Sprintf(" %s successfully created", name),
		})
	})

	// PUT - update a person details
	router.PUT("/books", func(c *gin.Context) {
		var buffer bytes.Buffer
		id := c.Query("BookID")
		title := c.PostForm("title")
		authors := c.PostForm("authors")
		stmt, err := db.Prepare("update books set title= ?, authors= ? where BookID= ?;")
		if err != nil {
			fmt.Print(err.Error())
		}
		_, err = stmt.Exec(title, authors, id)
		if err != nil {
			fmt.Print(err.Error())
		}

		// Fastest way to append strings
		buffer.WriteString(title)
		buffer.WriteString(" ")
		buffer.WriteString(authors)
		defer stmt.Close()
		name := buffer.String()
		c.JSON(http.StatusOK, gin.H{
			"message": fmt.Sprintf("Successfully updated to %s", name),
		})
	})

	// Delete resources
	router.DELETE("/books", func(c *gin.Context) {
		id := c.Query("id")
		stmt, err := db.Prepare("delete from books where id= ?;")
		if err != nil {
			fmt.Print(err.Error())
		}
		_, err = stmt.Exec(id)
		if err != nil {
			fmt.Print(err.Error())
		}
		c.JSON(http.StatusOK, gin.H{
			"message": fmt.Sprintf("Successfully deleted book: %s", id),
		})
	})
	router.Run(":3000")
}
