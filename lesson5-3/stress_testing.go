package main

import (
	"fmt"
	//	"io/ioutil"
	"net/http"
	"sort"
	"sync"
	"time"
)

// 10个协程，每个循环100个请求，共1000次请求。响应时间倒序后取第500个时间
const concurrence int = 10
const testcount int = 100
const percent int = 50
const testurl string = "http://www.baidu.com"

var lock sync.Mutex
var result costs
var wg sync.WaitGroup

func main() {

	for i := 0; i < concurrence; i++ {
		wg.Add(1)
		go bachtest(i)
	}

	wg.Wait()
	fmt.Printf("共%v\n", result.Len())
	sort.Sort(result)
	fmt.Printf("95响应时间：%v\n", result[percent].duration)
}

func bachtest(i int) {
	c, _ := test(testcount, i)
	lock.Lock()
	result = append(result, c...)
	lock.Unlock()
	wg.Done()
	fmt.Printf("第%v个，共%v\n", i, c.Len())
}

func test(count int, index int) (costs, error) {
	var c costs
	for i := 0; i < count; i++ {
		d, _ := HTTPRequest()
		c = append(c, cost{duration: d})
		if i%10 == 0 {
			fmt.Printf("第%v组第%v个\n", index, i)
		}
	}

	return c, nil
}

func HTTPRequest() (float64, error) {

	client := &http.Client{}
	req, err := http.NewRequest("GET", testurl, nil)
	if err != nil {
		return 0, err
	}

	start := time.Now()
	//发送请求
	res, err := client.Do(req)
	if err != nil {
		return 0.0, err
	}
	//计时返回
	duration := time.Since(start)
	//延时关闭句柄
	defer res.Body.Close()
	//	fmt.Printf("%v\n", duration)
	return duration.Seconds(), nil
}

// 排序结构
type cost struct {
	duration float64
}

type costs []cost

func (c costs) Len() int {
	return len(c)
}

// 降序
func (c costs) Less(i, j int) bool {
	return c[i].duration > c[j].duration
}

func (c costs) Swap(i, j int) {
	c[i], c[j] = c[j], c[i]
}
