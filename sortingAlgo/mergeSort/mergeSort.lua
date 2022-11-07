local function mergeSort(t)
    local n = #t
    if n < 2 then
        return t
    end
    local mid = math.floor(n / 2)
    local left = {}
    local right = {}
    for i = 1, mid do
        left[i] = t[i]
    end
    for i = mid + 1, n do
        right[i - mid] = t[i]
    end
    left = mergeSort(left)
    right = mergeSort(right)
    local i = 1
    local j = 1
    local k = 1
    while i <= #left and j <= #right do
        if left[i] < right[j] then
            t[k] = left[i]
            i = i + 1
        else
            t[k] = right[j]
            j = j + 1
        end
        k = k + 1
    end
    while i <= #left do
        t[k] = left[i]
        i = i + 1
        k = k + 1
    end
    while j <= #right do
        t[k] = right[j]
        j = j + 1
        k = k + 1
    end
    return t
end

local t = { 3, 2, 1, 4, 5, 6, 7, 8, 9, 10 }
mergeSort(t)
print(table.concat(t, ", "))