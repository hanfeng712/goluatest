function printmsg() 
	print("hello world") 
end 

function process_request(reqCtx)
    local uri_path = go.get_uri_path(reqCtx)
    print(uri_path)
    local count = go.write(reqCtx, uri_path)
    if count ~= string.len(uri_path) then
        print("write count is", count, "length of uri_path is", string.len(uri_path))
    end
end

function addFuncLua(first)
	print("2:lua call C == addFuncLua:value:" .. tostring(first))
	print("addFuncLua:luatime:" .. tostring(go.luatime)
	local result = go.cAddFuncGo(1,2,3)
	print("over ================== result:" .. tostring(result))
end