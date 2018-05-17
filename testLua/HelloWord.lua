function printmsg() 
	print("hello world") 
end 

function process_request(reqCtx)
    local uri_path = go.httpclient.get_uri_path(reqCtx)
    print(uri_path)
    local count = go.write(reqCtx, uri_path)
    if count ~= string.len(uri_path) then
        print("write count is", count, "length of uri_path is", string.len(uri_path))
    end
end

function addFuncLua(first)
	print("2:lua call C == addFuncLua:value:" .. tostring(first))
	local result = go.httpclient.cAddFuncGo(first)
	print("over ================== result:" .. tostring(result))
end